#!/usr/bin/python
import sys
import subprocess
import os
import stat
from os import path

# returns number of failed tests
def run(test_dir):
	test_list = []

	# grab all executables in the given test directory
	executable = stat.S_IEXEC | stat.S_IXGRP | stat.S_IXOTH
	for filename in os.listdir(test_dir):
		print "is %s a file?" % filename
		fullpath = path.join(test_dir,filename)
		if os.path.isfile(fullpath):
			st = os.stat(fullpath)
			mode = st.st_mode
			if mode & executable:
				test_list += [fullpath]
	
	print test_list

	failed_tests = []
	passed_tests = []

	# build all tests and run them, and gather results
	for test in test_list:
		# run application
		# TODO: Probably useful to set the working directory to something different
		process = subprocess.Popen(test)
		# output is a tuple of (stdoutdata, stderrdata)
		# this also indirectly updates the return value
		# TODO: Probably interesting to store return value and stdout/stderr to print back in a test log
		output = process.communicate()[0]
		returned_value = process.returncode

		if returned_value == 0:
			passed_tests += [test]
		else:
			print "Failed test: %s with return value %d" % (test, returned_value)
			failed_tests += [test]


	if len(passed_tests + failed_tests) == 0:
		print "No tests to execute"
	else:
		print "Test results:"
		print "%f%% of tests passed." % ( 100.0 * len(passed_tests) / len(passed_tests + failed_tests) )

	return len(failed_tests)

if __name__ == '__main__':
	if len(sys.argv) != 2:
		print "Usage: %s <test directory>" % sys.argv[0]
		sys.exit()
	if not os.path.isdir(sys.argv[1]):
		print "%s is not a directory" % sys.argv[1]
		sys.exit()
	run(sys.argv[1])
	sys.exit()

#!/usr/bin/python
import pickle
import sys
import subprocess
from os import path

# returns number of failed tests
def run():
	failed_tests = []
	passed_tests = []

	# build all tests and run them, and gather results
	for test in test_list:
		# run application
		# TODO: Probably useful to set the working directory to something different
		process = subprocess.Popen([test[1]])
		# output is a tuple of (stdoutdata, stderrdata)
		# this also indirectly updates the return value
		# TODO: Probably interesting to store return value and stdout/stderr to print back in a test log
		output = process.communicate()[0]
		returned_value = process.returncode

		if returned_value == 0:
			passed_tests += [test[0]]
		else:
			print "Failed test: %s with return value" % (test[0], returned_value)
			failed_tests += [test[0]]


	if len(passed_tests + failed_tests) == 0:
		print "No tests to execute"
	else:
		print "Test results:"
		print "%f%% of tests passed." % ( 100.0 * len(passed_tests) / len(passed_tests + failed_tests) )

	return len(failed_tests)

if __name__ == '__main__':
	sys.exit()

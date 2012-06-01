# This is an scons script to build the library
# Projects in different IDEs should make an scons call to this file

from os import path

# directory info
viking_dirs = { 
'target': 'viking',
'src': 'source/src',
'include': 'source/include',
'build': 'build',
'obj': 'obj',
'bin': 'bin',
'release': 'Release',
'debug': 'Debug',
'demos': 'demos',
'test': 'Test'
}

# compiler flags
viking_flags = {
'common': [ '-std=c++0x', '-Wall' ],
'debug': [ '-g', '-D_DEBUG' ],
'release': [ '-O2', '-DNDEBUG' ],
}

# libraries to link
viking_libs = {
'common': [ 'Irrlicht', 'GL' ]
}

# will be either viking_dirs['debug'] or viking_dirs['release'] depending on script arguments
build_configuration = ''

# pick up "debug" argument from command line input. Defaults to 0 (false).
if ARGUMENTS.get('debug', 0):
	build_configuration = viking_dirs['debug']
else:
	build_configuration = viking_dirs['release']

# create environment
env = Environment()

# add common compiler flags
env.Append(CPPFLAGS = viking_flags['common'])

# add include directory
env.Append(CPPPATH = path.abspath(viking_dirs['include']))

configuration_path = ''

# conditionally add compiler flags
if build_configuration == viking_dirs['debug']:
	env.Append(CPPFLAGS = viking_flags['debug'])
	configuration_path = viking_dirs['debug']
else:
	env.Append(CPPFLAGS = viking_flags['release'])
	configuration_path = viking_dirs['release']

# compose path to build of Viking
viking_dirs['build_obj'] = path.abspath(path.join(viking_dirs['build'], configuration_path, viking_dirs['obj']))
viking_dirs['build_bin'] = path.abspath(path.join(viking_dirs['build'], configuration_path, viking_dirs['bin']))

# compose path to build of Viking tests
viking_dirs['test_obj'] = path.abspath(path.join(viking_dirs['build'], viking_dirs['test'] + configuration_path, viking_dirs['obj']))
viking_dirs['test_bin'] = path.abspath(path.join(viking_dirs['build'], viking_dirs['test'] + configuration_path, viking_dirs['bin']))

# export variables so other scripts can Import them
Export('env viking_dirs build_configuration viking_libs')

# Builds Viking game
SConscript('source/SConscript')

# Builds and runs test cases
SConscript('test/SConscript')

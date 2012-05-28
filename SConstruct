# This is an scons script to build the library
# Projects in different IDEs should make an scons call to this file

from os import path

# directory info
viking_dirs = { 
'target': 'viking',
'src': 'src',
'include': 'include',
'build': 'build',
'obj': 'obj',
'bin': 'bin',
'release': 'Release',
'debug': 'Debug',
'demos': 'demos',
}

# compiler flags
viking_flags = {
'common': [ '-std=c++0x', '-Wall' ],
'debug': [ '-g', '-D_DEBUG' ],
'release': [ '-O2', '-DNDEBUG' ],
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

viking_dirs['build_obj'] = path.join(viking_dirs['build'], configuration_path, viking_dirs['obj'])
viking_dirs['build_bin'] = path.join(viking_dirs['build'], configuration_path, viking_dirs['bin'])

# export variables so other scripts can Import them
Export('env viking_dirs build_configuration')

# Builds Viking game
SConscript('SConscript')

# env.Append(LIBPATH = path.abspath(viking_dirs['build_bin']))
# env.Append(LIBS = viking_dirs['target'])

# Builds Viking demos
# SConscript( path.join(viking_dirs['demos'], 'SConscript') )

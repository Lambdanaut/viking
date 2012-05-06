# directory info
viking_dirs = { 
'target' : 'libviking',
'src' : 'src',
'include' : 'include',
'build' : 'build',
'obj' : 'obj',
'bin' : 'bin',
'release' : 'Release',
'debug' : 'Debug',
}

# compiler flags
viking_flags = {
'common' : [ '-std=c++0x', '-Wall' ],
'debug' : [ '-g', '-D_DEBUG' ],
'release' : [ '-O2', '-DNDEBUG' ],
}

# pick up "debug" argument from command line input. Defaults to 0 (false).
debug = ARGUMENTS.get('debug', 0)

# export symbols to scripts
Export('viking_dirs viking_flags debug')

# build viking library
SConscript('SConscript')

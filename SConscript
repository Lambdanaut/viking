# This is an scons script to build the library
# Projects in different IDEs should make a call to this file

# python libraries used in this file
from glob import glob
from os import path

# import scons environment variables
Import('viking_dirs viking_flags debug')

# picks up all files ending with .cpp in the root project folder
viking_sources = glob( path.join(viking_dirs['src'], "*.cpp") )

# list of all libraries to be linked
viking_libs = """\
SDLmain
SDL
GL
"""

# create environment
env = Environment()

# add libraries to environment
env.Append(LIBS = viking_libs.splitlines())

# compile with the C++11/C++0x standard
env.Append(CPPFLAGS = viking_flags['common'])

# add include directory
env.Append(CPPPATH = viking_dirs['include'])

configuration_path = ''

# conditionally add debug symbols and set the build path
if debug:
	env.Append(CPPFLAGS = viking_flags['debug'])
	configuration_path = "Debug"
else:
	env.Append(CPPFLAGS = viking_flags['release'])
	configuration_path = "Release"

build_obj_directory = path.join(viking_dirs['build'], configuration_path, viking_dirs['obj'])
build_bin_directory = path.join(viking_dirs['build'], configuration_path, viking_dirs['bin'])

# build object files
objects = [ env.Object(source = src_file,
		       target = path.join(build_obj_directory, path.splitext( path.basename(src_file) )[0]) )
		       for src_file in viking_sources ]

# flattens list, since env.Object returns a list of items...
objects = sum(objects, [])

# TODO: Optionally build a static or dynamic library
env.StaticLibrary(target = path.join(build_bin_directory, viking_dirs['target']), source = objects)

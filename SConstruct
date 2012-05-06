# This is an scons script to build the library
# Projects in different IDEs should make a call to this file

# python libraries used in this file
from glob import glob
from os import path

# directories
viking_target = "libviking"
src_directory = "."
build_directory = "build"
obj_directory = "obj"
bin_directory = "bin"
release_directory = "Release"
debug_directory = "Debug"

# picks up all files ending with .cpp in the root project folder
viking_sources = glob( path.join(src_directory, "*.cpp") )

# list of all libraries to be linked
viking_libs = """\
SDLmain
SDL
GL
"""

# picks up "debug" argument from command line input
debug = ARGUMENTS.get('debug', 0)

# create environment
env = Environment()

# add libraries to environment
env.Append(LIBS = viking_libs.splitlines())

# compile with the C++11/C++0x standard
env.Append(CPPFLAGS = ' -std=c++0x')

configuration_path = "Release"

# conditionally add debug symbols and set the build path
if debug:
	env.Append(CPPFLAGS = ' -g')
	configuration_path = "Debug"

build_obj_directory = path.join(build_directory, configuration_path, obj_directory)
build_bin_directory = path.join(build_directory, configuration_path, bin_directory)

# build object files
objects = [ env.Object(source = src_file,
		       target = path.join(build_obj_directory, path.splitext( path.basename(src_file) )[0]) )
		       for src_file in viking_sources ]

# flattens list, since env.Object returns a list of items...
objects = sum(objects, [])

# TODO: Optionally build a static or dynamic library
env.StaticLibrary(target = path.join(build_bin_directory, viking_target), source = objects)

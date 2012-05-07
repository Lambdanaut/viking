# python libraries used in this file
from glob import glob
from os import path

# import scons environment variables
Import('env viking_dirs')

# list of all libraries to be linked
viking_libs = [ 'SDLmain', 'SDL', 'GL' ]

# picks up all files ending with .cpp in the root project folder
viking_sources = glob( path.join(viking_dirs['src'], "*.cpp") )


# build object files
objects = [ env.SharedObject(source = src_file,
		       target = path.join(viking_dirs['build_obj'], path.splitext( path.basename(src_file) )[0]) )
		       for src_file in viking_sources ]

# flattens list, since env.Object returns a list of items...
objects = sum(objects, [])

# TODO: Optionally build a static or dynamic library
env.SharedLibrary(target = path.join(viking_dirs['build_bin'], viking_dirs['target']),
			source = objects,
			LIBS = viking_libs)

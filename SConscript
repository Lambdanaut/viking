# python libraries used in this file
from glob import glob
import os
from os import path
import fnmatch

# import scons environment variables
Import('env viking_dirs')

# list of all libraries to be linked
viking_libs = [ 'Irrlicht', 'GL' ]

# picks up all files ending with .cpp in the source folders
viking_sources = []
for root, dirnames, filenames in os.walk('src'):
    for filename in fnmatch.filter(filenames, '*.cpp'):
        viking_sources.append(path.join(root,filename))

# build object files
objects = [ env.Object(source = src_file,
		       target = path.join(viking_dirs['build_obj'], path.splitext( path.basename(src_file) )[0]) )
		       for src_file in viking_sources ]

# flattens list, since env.Object returns a list of items...
objects = sum(objects, [])

env.Program(target = path.join(viking_dirs['build_bin'], viking_dirs['target']),
			source = objects,
			LIBS = viking_libs)

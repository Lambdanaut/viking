viking_target = "viking"

viking_sources = """\
vikingroot.cpp
gametime.cpp
gameobjectengine.cpp
gameobject.cpp
eventsystem.cpp
"""

viking_libs = """\
SDL
GL
"""

env = Environment()
env.Append(LIBS = viking_libs.splitlines())

env.Library(target=viking_target, source=viking_sources.splitlines())

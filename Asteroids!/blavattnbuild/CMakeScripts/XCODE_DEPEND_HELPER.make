# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.asteroids.Debug:
PostBuild.glfw.Debug: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Debug/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.Debug: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Debug/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.Debug: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Debug/asteroids.app/Contents/MacOS/asteroids
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Debug/asteroids.app/Contents/MacOS/asteroids:\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Debug/libglfw3.a\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Debug/libglad.a\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Debug/libglfw3.a
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Debug/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.Debug:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Debug/libglad.a:
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Debug/libglad.a


PostBuild.glfw.Debug:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Debug/libglfw3.a:
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Debug/libglfw3.a


PostBuild.asteroids.Release:
PostBuild.glfw.Release: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Release/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.Release: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Release/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.Release: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Release/asteroids.app/Contents/MacOS/asteroids
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Release/asteroids.app/Contents/MacOS/asteroids:\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Release/libglfw3.a\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Release/libglad.a\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Release/libglfw3.a
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Release/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.Release:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Release/libglad.a:
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Release/libglad.a


PostBuild.glfw.Release:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Release/libglfw3.a:
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Release/libglfw3.a


PostBuild.asteroids.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/MinSizeRel/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.MinSizeRel: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/MinSizeRel/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.MinSizeRel: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/MinSizeRel/asteroids.app/Contents/MacOS/asteroids
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/MinSizeRel/asteroids.app/Contents/MacOS/asteroids:\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/MinSizeRel/libglfw3.a\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/MinSizeRel/libglad.a\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/MinSizeRel/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.MinSizeRel:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/MinSizeRel/libglad.a:
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/MinSizeRel/libglad.a


PostBuild.glfw.MinSizeRel:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/MinSizeRel/libglfw3.a


PostBuild.asteroids.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.RelWithDebInfo: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.RelWithDebInfo: /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids:\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/RelWithDebInfo/libglfw3.a\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/RelWithDebInfo/libglad.a\
	/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.RelWithDebInfo:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/RelWithDebInfo/libglad.a:
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/RelWithDebInfo/libglad.a


PostBuild.glfw.RelWithDebInfo:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/RelWithDebInfo/libglfw3.a




# For each target create a dummy ruleso the target does not have to exist
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Debug/libglad.a:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/MinSizeRel/libglad.a:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/RelWithDebInfo/libglad.a:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/Release/libglad.a:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Debug/libglfw3.a:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/MinSizeRel/libglfw3.a:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
/Users/jaredblavatt/Documents/GitHub/module-transformations-geam-traphics/Asteroids!/blavattnbuild/glfw-3.2/src/Release/libglfw3.a:

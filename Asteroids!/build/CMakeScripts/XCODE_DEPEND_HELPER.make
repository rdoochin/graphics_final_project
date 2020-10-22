# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.asteroids.Debug:
PostBuild.glfw.Debug: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Debug/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.Debug: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Debug/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.Debug: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Debug/asteroids.app/Contents/MacOS/asteroids
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Debug/asteroids.app/Contents/MacOS/asteroids:\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Debug/libglfw3.a\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Debug/libglad.a\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Debug/libglfw3.a
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Debug/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.Debug:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Debug/libglad.a:
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Debug/libglad.a


PostBuild.glfw.Debug:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Debug/libglfw3.a:
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Debug/libglfw3.a


PostBuild.asteroids.Release:
PostBuild.glfw.Release: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Release/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.Release: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Release/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.Release: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Release/asteroids.app/Contents/MacOS/asteroids
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Release/asteroids.app/Contents/MacOS/asteroids:\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Release/libglfw3.a\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Release/libglad.a\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Release/libglfw3.a
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Release/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.Release:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Release/libglad.a:
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Release/libglad.a


PostBuild.glfw.Release:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Release/libglfw3.a:
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Release/libglfw3.a


PostBuild.asteroids.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.MinSizeRel: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.MinSizeRel: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids:\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/MinSizeRel/libglad.a\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.MinSizeRel:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/MinSizeRel/libglad.a:
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/MinSizeRel/libglad.a


PostBuild.glfw.MinSizeRel:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a


PostBuild.asteroids.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.RelWithDebInfo: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.RelWithDebInfo: /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids:\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/RelWithDebInfo/libglad.a\
	/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.RelWithDebInfo:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/RelWithDebInfo/libglad.a:
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/RelWithDebInfo/libglad.a


PostBuild.glfw.RelWithDebInfo:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a




# For each target create a dummy ruleso the target does not have to exist
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Debug/libglad.a:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/MinSizeRel/libglad.a:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/RelWithDebInfo/libglad.a:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/Release/libglad.a:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Debug/libglfw3.a:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
/Users/rebekahdoochin/senior_year/graphics/module-intro-getting-started-rdoochin/module-algorithms-geam-traphics/Asteroids!/build/glfw-3.2/src/Release/libglfw3.a:

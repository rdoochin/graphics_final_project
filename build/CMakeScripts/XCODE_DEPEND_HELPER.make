# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.glad.Debug:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/Debug/libglad.a:
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Debug/libglad.a


PostBuild.glfw.Debug:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Debug/libglfw3.a:
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Debug/libglfw3.a


PostBuild.inside_outside.Debug:
PostBuild.glfw.Debug: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Debug/inside_outside.app/Contents/MacOS/inside_outside
PostBuild.glad.Debug: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Debug/inside_outside.app/Contents/MacOS/inside_outside
PostBuild.glfw.Debug: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Debug/inside_outside.app/Contents/MacOS/inside_outside
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/Debug/inside_outside.app/Contents/MacOS/inside_outside:\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Debug/libglfw3.a\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/Debug/libglad.a\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Debug/libglfw3.a
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Debug/inside_outside.app/Contents/MacOS/inside_outside


PostBuild.glad.Release:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/Release/libglad.a:
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Release/libglad.a


PostBuild.glfw.Release:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Release/libglfw3.a:
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Release/libglfw3.a


PostBuild.inside_outside.Release:
PostBuild.glfw.Release: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Release/inside_outside.app/Contents/MacOS/inside_outside
PostBuild.glad.Release: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Release/inside_outside.app/Contents/MacOS/inside_outside
PostBuild.glfw.Release: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Release/inside_outside.app/Contents/MacOS/inside_outside
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/Release/inside_outside.app/Contents/MacOS/inside_outside:\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Release/libglfw3.a\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/Release/libglad.a\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Release/libglfw3.a
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/Release/inside_outside.app/Contents/MacOS/inside_outside


PostBuild.glad.MinSizeRel:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/MinSizeRel/libglad.a:
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/MinSizeRel/libglad.a


PostBuild.glfw.MinSizeRel:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/MinSizeRel/libglfw3.a


PostBuild.inside_outside.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/MinSizeRel/inside_outside.app/Contents/MacOS/inside_outside
PostBuild.glad.MinSizeRel: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/MinSizeRel/inside_outside.app/Contents/MacOS/inside_outside
PostBuild.glfw.MinSizeRel: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/MinSizeRel/inside_outside.app/Contents/MacOS/inside_outside
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/MinSizeRel/inside_outside.app/Contents/MacOS/inside_outside:\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/MinSizeRel/libglfw3.a\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/MinSizeRel/libglad.a\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/MinSizeRel/inside_outside.app/Contents/MacOS/inside_outside


PostBuild.glad.RelWithDebInfo:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/RelWithDebInfo/libglad.a:
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/RelWithDebInfo/libglad.a


PostBuild.glfw.RelWithDebInfo:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a


PostBuild.inside_outside.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/RelWithDebInfo/inside_outside.app/Contents/MacOS/inside_outside
PostBuild.glad.RelWithDebInfo: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/RelWithDebInfo/inside_outside.app/Contents/MacOS/inside_outside
PostBuild.glfw.RelWithDebInfo: /Users/davidziman/graphics/module-algorithms-geam-traphics/build/RelWithDebInfo/inside_outside.app/Contents/MacOS/inside_outside
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/RelWithDebInfo/inside_outside.app/Contents/MacOS/inside_outside:\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/RelWithDebInfo/libglad.a\
	/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/davidziman/graphics/module-algorithms-geam-traphics/build/RelWithDebInfo/inside_outside.app/Contents/MacOS/inside_outside




# For each target create a dummy ruleso the target does not have to exist
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/Debug/libglad.a:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/MinSizeRel/libglad.a:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/RelWithDebInfo/libglad.a:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/Release/libglad.a:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Debug/libglfw3.a:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/MinSizeRel/libglfw3.a:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
/Users/davidziman/graphics/module-algorithms-geam-traphics/build/glfw-3.2/src/Release/libglfw3.a:

FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/nonstop_ar_pose/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/nonstop_ar_pose/msg/__init__.py"
  "../src/nonstop_ar_pose/msg/_ARMarker.py"
  "../src/nonstop_ar_pose/msg/_ARMarkers.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)

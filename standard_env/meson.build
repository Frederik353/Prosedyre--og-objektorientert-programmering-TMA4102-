project('testproject', 'cpp',
  version : '0.1',
  default_options : ['warning_level=2',
                     'cpp_std=c++20',
                     'c_std=c17',
                     'default_library=static'])

# Windows compilation has no pre-packaged SDL2 available, and compilation takes a while.
# If you want to compile from source, remove everything but the contents of the else clause.
if host_machine.system() == 'windows'
  sdl2_dep = subproject('sdl2_windows').get_variable('sdl2_windows_dep')
else
  sdl2_dep = dependency('sdl2')
endif

# animationwindow_dep = dependency('animationwindow', fallback: ['animationwindow', 'animationwindow_dep'])
# TODO: slett std_lib_facilities fra animationwindow. Kommenter samtidig ut de to følgende linjene
# std_lib_facilities_dep = dependency('std_lib_facilities', fallback: ['std_lib_facilities', 'std_lib_facilities_dep'])


if host_machine.system() == 'linux'
  compiler_flags = ['-Wconversion', '-fdiagnostics-color=always', '-Werror=return-type']
else
  compiler_flags = ['-Wconversion', '-fdiagnostics-color=always', '-Werror=return-type', '-fcolor-diagnostics', '-fansi-escape-codes']
endif



# ---------------- my setup ----------------

# configure_file(input: './missing_files/libstdc++-6.dll', output: 'libstdc++-6.dll', copy: true)
# configure_file(input: './missing_files/meson-vscode.env', output: 'meson-vscode.env', copy: true)
# configure_file(input: './missing_files/SDL2_image.dll', output: 'SDL2_image.dll', copy: true)
# configure_file(input: './missing_files/SDL2.dll', output: 'SDL2.dll', copy: true)




std_lib_facilities_dep = subproject('std_lib_facilities')
std_lib_facilities_dep = std_lib_facilities_dep.get_variable('std_lib_facilities_dep')

animationwindow_dep = subproject('animationwindow').get_variable('animationwindow_dep')


inc_dirs = include_directories('./include')

src = [
'./src/optimizationTask.cpp',
'./src/Stopwatch.cpp',
]

exe = executable(
  'program',
  [src, './src/main.cpp'],
  dependencies : [animationwindow_dep, sdl2_dep, std_lib_facilities_dep],
  cpp_args : compiler_flags,
  include_directories: inc_dirs,
)

# ------------- tests ----------------

gtest_proj = subproject('gtest')
gtest_dep  = gtest_proj.get_variable('gtest_main_dep')
gmock_dep  = gtest_proj.get_variable('gmock_dep')

# inc_dirs = include_directories('tests')
test_inc_dirs = include_directories('./tests/include')

tests = []

test_executable = executable(
    'run_tests',
    [tests, src],
    dependencies : [animationwindow_dep, sdl2_dep, std_lib_facilities_dep, gtest_dep, gmock_dep],
    include_directories: [test_inc_dirs, inc_dirs]
)


# dependencies : [animationwindow_dep, sdl2_dep, std_lib_facilities_dep],
test('unit_tests', test_executable)

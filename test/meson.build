test_sources = [
    'tests/CFGPathTest.cpp',
    'tests/GenerateAppHashTest.cpp',
]

test_dependencies = [
    catch2_with_main_dep,
    cpp_libcfgpath_dep,
]

testexe = executable('testexe', test_sources,
                     dependencies: test_dependencies)

test_args = []

test('libCFGPath unit tests', testexe, args: test_args)
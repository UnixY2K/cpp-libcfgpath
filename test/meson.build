test_sources = [
    'source.cpp',
    'tests/CFGPathTest.cpp',
    'tests/GenerateAppHashTest.cpp',
]

test_dependencies = [
    catch2_dep,
    cpp_libcfgpath_dep,
]

testexe = executable('testexe', test_sources,
                     dependencies: test_dependencies)

test_args = []

test('libCFGPath unit tests', testexe, args: test_args)
project( san-issue-detector )

set( HEADERS
    ""
)

set( SOURCES
    "app/main.cpp"
    "src/uni/asan/collection.hpp"
    "src/uni/asan/collection.cpp"
    "src/uni/ubsan/collection.hpp"
    "src/uni/ubsan/collection.cpp"
)

# treat_all_warnings_as_errors()

add_executable( ${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        ${SOURCE_DIR}/san-issue-detector/src
)

install( TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

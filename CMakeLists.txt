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

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    PUBLIC_HEADER "${HEADERS}"
)

install( TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION usr/lib
    LIBRARY DESTINATION usr/lib
    PUBLIC_HEADER DESTINATION usr/include
    RUNTIME DESTINATION usr/bin
)

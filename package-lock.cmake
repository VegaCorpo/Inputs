# Common
CPMDeclarePackage(Common
    GITHUB_REPOSITORY VegaCorpo/Common
    GIT_TAG features/camera_mouse_rotation
    SYSTEM YES
    EXCLUDE_FROM_ALL YES
)

# glfw
CPMDeclarePackage(glfw
    GITHUB_REPOSITORY glfw/glfw
    GIT_TAG 3.4
    OPTIONS
        "GLFW_BUILD_EXAMPLES OFF"
        "GLFW_BUILD_TESTS OFF"
        "GLFW_BUILD_DOCS OFF"
        "BUILD_SHARED_LIBS ON"
        "GLFW_BUILD_X11 ON"
        "GLFW_BUILD_WAYLAND OFF"
    SYSTEM YES
    EXCLUDE_FROM_ALL YES
)

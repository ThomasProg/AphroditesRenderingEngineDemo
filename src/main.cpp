#include <iostream>

#include <Context.hpp>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags


static void onError(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
 
static void onInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
 
int main()
{
    glfwSetErrorCallback(onError);
 
    if (!glfwInit())
    {
        std::cout << "glfw couldn't init" << std::endl;
        return EXIT_FAILURE;
    }
 
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* window = glfwCreateWindow(600, 500, "Aphrodite's Rendering Engine Demo", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout << "glfw couldn't create window" << std::endl;
        return EXIT_FAILURE;
    }
 
    glfwSetKeyCallback(window, onInput);

    {
        // Create an instance of the Importer class
        Assimp::Importer importer;

        // And have it read the given file with some example postprocessing
        // Usually - if speed is not the most important aspect for you - you'll
        // probably to request more postprocessing than we do in this example.
        const aiScene* scene = importer.ReadFile("",
            aiProcess_CalcTangentSpace       |
            aiProcess_Triangulate            |
            aiProcess_JoinIdenticalVertices  |
            aiProcess_SortByPType);
        if (scene == nullptr)
            std::cout << "Scene could not be loaded" << std::endl;















        ARE::VulkanContextCreateInfo createInfo;
        createInfo.appName = "Aphrodite's Rendering Engine Demo";
        createInfo.appVersion = VK_MAKE_VERSION(1,0,0);

        uint32_t nbExtensions;
        const char** extensionsName = glfwGetRequiredInstanceExtensions(&nbExtensions);
        createInfo.requiredExtensions = std::vector<const char*>(extensionsName, extensionsName + nbExtensions);

        ARE::Context context = ARE::Context(createInfo); 


















        while (!glfwWindowShouldClose(window))
        {

            glfwPollEvents();
        }
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    return EXIT_SUCCESS;
}
 
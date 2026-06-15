#include <vulkan90/vulkan.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define APP_LAYER_PROP_MAX 256u
#define APP_EXT_PROP_MAX 256u

typedef struct AppDataVk{
    VkLayerProperties layerProp[APP_LAYER_PROP_MAX];
    VkExtensionProperties extProp[APP_EXT_PROP_MAX];
    VkApplicationInfo info;
    VkInstanceCreateInfo instanceInfo;
} AppDataVk;

static AppDataVk Global_App_Vk = { 0u };

int main( void ) {
    AppDataVk *app = &Global_App_Vk;
    VkResult result;
    VkInstance instance;
    unsigned count, count1,  i, i1;

    count = APP_LAYER_PROP_MAX;
    result = vkEnumerateInstanceLayerProperties( &count, app->layerProp );
    assert( VK_SUCCESS <= result && count <= APP_LAYER_PROP_MAX );
    for ( i = 0u; i < count; ++i ) {
        puts( app->layerProp[i].layerName );
        count1 = APP_EXT_PROP_MAX;
        result = vkEnumerateInstanceExtensionProperties( app->layerProp[i].layerName, &count1, app->extProp );
        if ( count1 ) puts( "layer extension properties: " );
        assert( VK_SUCCESS <= result && count1 <= APP_EXT_PROP_MAX );
        for ( i1 = 0u; i1 < count1; ++i1 ) {
            puts( app->extProp[i1].extensionName );
        }
        puts( "=========================" );
    }

    puts( "extension properties:" );
    count = APP_EXT_PROP_MAX;
    result = vkEnumerateInstanceExtensionProperties( NULL, &count, app->extProp );
    assert( VK_SUCCESS <= result );
    for ( i = 0u; i < count; ++i ) {
        puts( app->extProp[i].extensionName );
    }

    app->info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app->instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    app->instanceInfo.pApplicationInfo = &app->info;
    result = vkCreateInstance( &app->instanceInfo, NULL, &instance );
    assert( result == VK_SUCCESS );

    vkDestroyInstance( instance, NULL );

    return EXIT_SUCCESS;
}

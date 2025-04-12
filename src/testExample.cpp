#include "GraphiLiteApp.h"

int main() {
    try {
        GraphiLite::GraphiLiteApp app;
        app.Run();
    } catch (const std::exception& e) {
        printf("Application Error: %s\n", e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

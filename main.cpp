#include "test.h"
#include "repo.h"
#include "service.h"
#include "rentalcart.h"
#include "ui.h"
#include <iostream>

int main() {
    Tests tests;
    tests.run();
    printf("All tests passed!\n");
    Repo repo;
    Rentalcart cart;
    Service service{ repo, cart};
    UI ui{ service };
    ui.run();
    return 0;
}
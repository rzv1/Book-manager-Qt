#include "test.h"
#include "repo.h"
#include "service.h"
#include "rentalcart.h"
#include "ui.h"
#include <iostream>

void run() {
    Tests tests;
    tests.run();
    cout << "Teste trecute!";
    Repo repo("books");
    Rentalcart cart;
    Service service{ repo, cart };
    UI ui{ service };
    ui.run();
}
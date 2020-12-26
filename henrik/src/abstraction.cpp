#include <iostream>

#include "open_spiel/games/tarok.h"
#include "open_spiel/spiel.h"

int main() {
  auto game = std::static_pointer_cast<const open_spiel::tarok::TarokGame>(
      open_spiel::LoadGame("tarok(players=3,rng_seed=0)"));
  std::cout << game->MaxGameLength() << std::endl;
}

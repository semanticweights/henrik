#include <iostream>

#include "mlpack/core.hpp"
#include "mlpack/methods/kmeans/kmeans.hpp"
#include "open_spiel/games/tarok.h"
#include "open_spiel/spiel.h"

using namespace open_spiel;
using namespace mlpack;

int main() {
  auto game = std::static_pointer_cast<const tarok::TarokGame>(
      LoadGame("tarok(players=3,rng_seed=0)"));
  kmeans::KMeans kmeans = kmeans::KMeans();

  std::cout << game->NumPlayers() << std::endl;
}

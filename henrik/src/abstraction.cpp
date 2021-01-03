#include "mlpack/core.hpp"
#include "mlpack/methods/kmeans/kmeans.hpp"
#include "open_spiel/games/tarok.h"
#include "open_spiel/spiel.h"

constexpr int kNumInfoSetsPerTraining = 1000;
constexpr int kNumClusters = 20;

void HandAbstraction(const open_spiel::tarok::TarokGame& game) {
  auto X = arma::mat(54, kNumInfoSetsPerTraining, arma::fill::zeros);

  for (size_t infoset_i = 0; infoset_i < kNumInfoSetsPerTraining; ++infoset_i) {
    auto state = game.NewInitialTarokState();
    // deal the cards
    state->ApplyAction(0);
    for (auto const& card_i : state->PlayerCards(state->CurrentPlayer())) {
      X(card_i, infoset_i) = 1.0;
    }
  }

  auto kmeans = mlpack::kmeans::KMeans(0);
  arma::mat centroids;
  kmeans.Cluster(X, kNumClusters, centroids);
  mlpack::data::Save("centroids.csv", centroids);
}

int main() {
  auto game = std::static_pointer_cast<const open_spiel::tarok::TarokGame>(
      open_spiel::LoadGame("tarok(players=3,rng_seed=0)"));
  HandAbstraction(*game);
}

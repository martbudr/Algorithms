#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 1e6;
int eval[N_MAX]; // static evaluation of a certain player
vector<int> children[N_MAX];

// a one that returns value
int minimax_1(int pos, int depth, bool player_max) { // pos - position, player_max - maximizing player
	if (depth == 0)
		return eval[pos];

	if (player_max) {
		int eval_max = INT_MIN;
		for (auto child : children[pos]) {
			eval[child] = minimax_1(child, depth - 1, !player_max);
			eval_max = max(eval[pos], eval[child]);
		}
		return eval_max;
	}
	else {
		int eval_min = INT_MAX;
		for (auto child : children[pos]) {
			eval[child] = minimax_1(child, depth - 1, !player_max);
			eval_min = min(eval[pos], eval[child]);
		}
		return eval_min;
	}
}

// a one that stores the value in eval[root]
void minimax_2(int pos, int depth, bool player_max) { // pos - position, player_max - maximizing player
	if (depth == 0)
		return;

	if (player_max) {
		eval[pos] = INT_MIN;
		for (auto child : children[pos]) {
			minimax_2(child, depth - 1, !player_max);
			eval[pos] = max(eval[pos], eval[child]);
		}
	}
	else {
		eval[pos] = INT_MAX;
		for (auto child : children[pos]) {
			minimax_2(child, depth - 1, !player_max);
			eval[pos] = min(eval[pos], eval[child]);
		}
	}
}

int main(void) {
	/// both functions are not tested
}
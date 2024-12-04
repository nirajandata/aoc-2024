import std;

std::vector<std::int64_t> parse(char* line) {
	std::vector<std::int64_t> result;
	auto token = std::strtok(line, " ");
	std::int8_t i{};
	while (token) {
		result.push_back(std::stoi(token));
		token = std::strtok(nullptr, " ");
		i++;
	}
	return result;
}

int main() {
	std::ifstream file("in.in");
	std::string line;
	size_t safe{};

	while (std::getline(file, line)) {
		auto data{ parse(line.data()) };
		bool order = data.at(0) > data.at(1);
		auto val = data.at(0)-1;
		if (order)
			val += 2;

		bool check = true;
		for (auto iter : data) {
			auto t = val - iter;
			if (not order)
				t *= -1;
			if (t < 1 or std::abs(t)>3) {
				check = false;
				break;
			}
			val = iter;
		}
		if (check) safe++;
	}

	std::println("Answer is {}",safe);

	return 0;
}

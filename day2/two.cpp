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

bool checker(auto t) {
	return (t < 1 or std::abs(t)>3);
}

int main() {
	std::ifstream file("in.in");
	std::string line;
	size_t safe{};

	while (std::getline(file, line)) {
		auto data{ parse(line.data()) };
		bool order = ((data.at(0) > data.at(1))+ (data.at(1)>data.at(2)) + (data.at(2)>data.at(3))) >2;

		auto val = data.at(0) - 1;
		if (order)
			val += 2;

		bool check = true;
		std::int64_t bruh = -2,ex=0;
		for (auto iter : data) {
			auto t = val - iter;
			if (not order)
				t *= -1;
			bool res = checker(t);
			if (bruh>-1) {
				ex = bruh - iter;
				if (not order) ex *= -1;
				res &= checker(ex);
				bruh = -1;
			}

			if(res){
				if (bruh == -2) {
					bruh = iter;
					continue;
				}
				check = false;
				break;
			}
			val = iter;
		}
		if (check) safe++;
	}

	std::println("Answer is {}", safe);

	return 0;
}

import std;

//using regex isn't fun!
std::int64_t parse(std::string_view line) {
	std::int64_t ans = 0;
	for (size_t i = 0;i < line.size();i++) {
		if (i + 4 < line.size() && line.substr(i, 4) == "mul(") {
			size_t j = i + 4;
			std::int64_t dig{}, mul{};
			while (j < line.size() && std::isdigit(line.at(j))) {
				dig = dig * 10 + static_cast<std::int64_t>(line.at(j)-'0');
				j++;
			}
			if (j < line.size() && line.at(j) == ',') {
				mul = dig;
				dig = 0;
				j++;
			}
			while (j < line.size() && std::isdigit(line.at(j))) {
				dig = dig * 10 + static_cast<std::int64_t>(line.at(j)-'0');
				j++;
			}
			if (j < line.size() && line.at(j) != ')')
				dig = 0;

			mul *= dig;
			ans += mul;
			j++;
		}
	}
	return ans;
}

int main() {
	std::ifstream file("in.in");
	std::string line;
	size_t ans{};

	while (std::getline(file, line)) {
		ans += parse(line);
	}
	std::println("Answer is {}", ans);

	return 0;
}

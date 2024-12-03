import std;

constexpr std::array<std::int64_t,2> parse(std::string_view line) {
	std::array<std::int64_t, 2> result{ 0 };
	std::from_chars(line.data(), line.data() + line.find(' '),result[0]);
	std::from_chars(line.data() + line.find_last_of(' ')+1, line.data() + line.size(), result[1]);
	return result;
}

int main() {
	std::ifstream file("in.in");
	std::string line;
	std::vector<std::int64_t> a, b;
	while (std::getline(file, line)) {
		auto [one, two] = parse(line);
		a.push_back(one);
		b.push_back(two);
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	std::int64_t ans=0;
	for (size_t i = 0;i < a.size();i++) {
	//	std::println(" {0} and {1} is ", a.at(i), b.at(i));
		ans += std::abs(a.at(i) - b.at(i));
	}
	std::println("Answer is {}",ans);

	return 0;
}


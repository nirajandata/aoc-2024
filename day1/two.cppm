import std;

constexpr std::array<std::int64_t,2> parse(std::string_view line) {
	std::array<std::int64_t, 2> result{ 0 };
	std::from_chars(line.data(), line.data() + line.find(' '),result[0]);
	std::from_chars(line.data() + line.find_last_of(' ')+1, line.data() + line.size(), result[1]);
	return result;
}

int main() {
	std::ifstream file("samp.in");

	std::string line;
	std::vector<std::int64_t> a;
	std::unordered_map<std::int64_t, std::int64_t> count;
	while (std::getline(file, line)) {
		auto [one, two] = parse(line);
		count[two]++;
		a.push_back(one);
	}

	std::int64_t ans{ 0 };
	for (auto iter : a)
		ans += iter * count[iter];
	std::println("Answer is {}",ans);

	return 0;
}

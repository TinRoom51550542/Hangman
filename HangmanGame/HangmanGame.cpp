#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <ctime> 
#include <cctype> 
#include <clocale>
#include <Windows.h>
#include <ctype.h>
#include <fstream>
#include <cstdlib>

std::string check;

void launchOfTheGame();

void drawHangman(int wrong) { //отрисовка виселицы в зависимости от количества ошибок
	switch (wrong) {
	case 1:
		std::cout << "\n"
			"\n"
			"\n"
			"\n"
			"\n"
			"\n"
			"\n"
			"\n"
			"\n"
			"\n"
			"\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 2:
		std::cout << "        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 3:
		std::cout << "        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";

		break;
	case 4:
		std::cout << "        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"      /               $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";

		break;
	case 5:
		std::cout << "        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"      /   \\           $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 6:
		std::cout << "        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"      / | \\           $\n"
			"        |             $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 7:
		std::cout << "        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"      / | \\           $\n"
			"        |             $\n"
			"       /              $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 8:
		std::cout << "        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"      / | \\           $\n"
			"        |             $\n"
			"       / \\            $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	default:
		std::cout << '\n';
	}
}

void checkYesOrNo(std::string& check) { //проверка на ввод 'да' или 'нет'
	transform(check.begin(), check.end(), check.begin(), tolower);
	if (check != "да" and check != "нет") {
		std::cout << "\nПожалуйста, введите 'да' или 'нет': ";
		std::getline(std::cin, check);
		checkYesOrNo(check);
	}
}

int checkOfInput(std::string c) { //проверка на ввод цифры
	bool flag = 0;
	for (int i = 0; i < c.length(); i++) {
		if (!isdigit(c[i])) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		std::cout << "Пожалуйста, введите данные корректно': ";
		std::getline(std::cin, c);
		checkOfInput(c);
	}
	else {
		return stoi(c);
	}
}

void checkOfPlayers(std::string& p) { //проверка на ввод количества игроков
	if (p != "1" and p != "2") {
		std::cout << "Пожалуйста, введите данные корректно': ";
		std::getline(std::cin, p);
		checkOfPlayers(p);
	}
}

std::string makingWord(std::ifstream& f) { //создание случайного слова из файла
	std::vector<std::string>words;
	std::string word;
	while (f >> word) {
		words.push_back(word);
	}
	random_shuffle(words.begin(), words.end());
	return words[0];
}

std::string makingWordFromCategories(int c) { //создание слова для введенной категории
	std::ifstream file;
	std::vector<std::string>words;
	switch (c) {
	case 1:
	{
		std::ifstream file("animals.txt");
		return makingWord(file);
	}
	case 2:
	{
		std::ifstream file("sport.txt");
		return makingWord(file);
	}
	case 3:
	{
		std::ifstream file("food.txt");
		return makingWord(file);
	}
	case 4:
	{
		std::ifstream file("nature.txt");
		return makingWord(file);
	}
	case 5:
	{
		std::ifstream file("colors.txt");
		return makingWord(file);
	}
	case 6:
	{
		std::ifstream file("jobs.txt");
		return makingWord(file);
	}
	case 7:
	{
		std::ifstream file("data.txt");
		return makingWord(file);
	}
	default:
	{
		std::cout << "Пожалуйста, введите данные корректно': ";
		std::string ch;
		std::getline(std::cin, ch);
		c = checkOfInput(ch);
		return makingWordFromCategories(c);
	}
	}
}

void game(int MAX_WRONG, int& wrong, std::string THE_WORD, std::string& used, std::string& soFar, short& flagIfGuessed) { //основной процесс игры
	std::cout << "\n\nОсталось " << (MAX_WRONG - wrong) << " попыток. \n";
	std::cout << "Вы использовали следующие буквы:\n" << used << std::endl;
	std::cout << "\nСлово:\n" << soFar << std::endl;
	char guess;
	std::cout << "\nВведите букву: ";
	std::cin >> guess;
	guess = toupper(guess);
	if (guess == 'я') {
		guess = 'Я';
	}
	while (used.find(guess) != std::string::npos) { //пока повторяется ввод ранее введенной буквы
		std::cout << "\nВы уже вводили " << guess << std::endl;
		std::cout << "Введите букву: ";
		std::cin >> guess;
		guess = toupper(guess);
	}
	system("cls");
	used += guess;
	if (THE_WORD.find(guess) != std::string::npos) { //если введенная буква есть в загаданном слове
		flagIfGuessed = 1;
		std::cout << "Верно! " << guess << " есть в слове. \n";
		drawHangman(wrong);
		for (int i = 0; i < THE_WORD.length(); ++i) { //обновить переменную soFar, включив в нее новую угаданную букву
			if (THE_WORD[i] == guess) {
				soFar[i] = guess;
			}
		}
	}
	else {
		std::cout << "Извините. " << guess << " нет в слове.\n";
		wrong++;
		drawHangman(wrong);
	}
}

void gameplayFor2Players(int MAX_WRONG, int& wrong, std::string THE_WORD, std::string& used, short& flagForPlayers, int& countWinFor1, int& countWinFor2, std::string Player1, std::string Player2) { //процесс игры для двух игроков
	wrong = 0;
	used = "";
	std::string soFar(THE_WORD.size(), '-');
	flagForPlayers = 1;
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		short flagIfGuessed = 0;
		if (flagForPlayers == 1) {
			std::cout << Player1 << ", твой ход! ";
		}
		else {
			std::cout << Player2 << ", твой ход! ";
		}
		game(MAX_WRONG, wrong, THE_WORD, used, soFar, flagIfGuessed);
		if (flagIfGuessed == 1) {
			continue;
		}
		if (flagForPlayers == 1) { //если первый игрок ввел неправильную букву, ход передается второму игроку
			flagForPlayers = 2;
		}
		else {
			flagForPlayers = 1;
		}
	}
	if (wrong == MAX_WRONG) {
		std::cout << std::endl;
		std::cout << "***********************" << std::endl;
		std::cout << "    Вы проиграли!    " << std::endl;
	}
	else
	{
		if (flagForPlayers == 1) {
			countWinFor1 += 1;
			std::cout << std::endl;
			std::cout << "*******************************" << std::endl;
			std::cout << "   Выиграл игрок " << Player1 << "!" << std::endl;
		}
		else {
			countWinFor2 += 1;
			std::cout << std::endl;
			std::cout << "*******************************" << std::endl;
			std::cout << "   Выиграл игрок " << Player2 << "!" << std::endl;
		}
	}
	std::cout << "\nЗагаданное слово - " << THE_WORD << std::endl;
	std::cin.ignore(1000, '\n');
	std::cout << "\nСчет:\t" << Player1 << " " << countWinFor1 << ':' << countWinFor2 << " " << Player2 << std::endl;
	std::cout << "\nПродолжить? 'да' или 'нет' (при вводе 'нет' вы переходите в главное меню, и статистика сбрасывается): ";
	std::string continueGame;
	std::getline(std::cin, continueGame);
	checkYesOrNo(continueGame);
	if (continueGame == "да") {
		system("cls");
		std::string choose_of_categories;
		std::cout << "\nВыберите категорию:" << std::endl;
		std::cout << "Животные - 1\n";
		std::cout << "Спорт - 2\n";
		std::cout << "Еда - 3\n";
		std::cout << "Природа - 4\n";
		std::cout << "Цвета - 5\n";
		std::cout << "Профессии - 6\n";
		std::cout << "Любая категория - 7\n";
		std::getline(std::cin, choose_of_categories);
		int chooseOfCategories = checkOfInput(choose_of_categories);
		THE_WORD = makingWordFromCategories(chooseOfCategories);
		system("cls");
		wrong = 0;
		used = "";
		std::string soFar(THE_WORD.size(), '-');
		flagForPlayers = 1;
		gameplayFor2Players(MAX_WRONG, wrong, THE_WORD, used, flagForPlayers, countWinFor1, countWinFor2, Player1, Player2);
	}
	else {
		system("cls");
		launchOfTheGame();
	}
}

void gameplayFor1Player(int MAX_WRONG, int& wrong, std::string THE_WORD, std::string& used, std::string& soFar, int& count) { //процесс игры для одного игрока
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		short flagIfGuessed = 0;
		game(MAX_WRONG, wrong, THE_WORD, used, soFar, flagIfGuessed);
	}
	if (wrong == MAX_WRONG) {
		std::cout << std::endl;
		std::cout << "***********************" << std::endl;
		std::cout << "*    Вы проиграли!    *" << std::endl;
		std::cout << "***********************" << std::endl;
	}
	else
	{
		count++;
		std::cout << std::endl;
		std::cout << "*********************" << std::endl;
		std::cout << "*    Вы угадали!    *" << std::endl;
		std::cout << "*********************" << std::endl;
	}
	std::cout << "\nЗагаданное слово - " << THE_WORD << std::endl;
	std::cin.ignore(1000, '\n');
	std::cout << "Количество правильных ответов: " << count << std::endl;
	std::cout << "\nПродолжить? 'да' или 'нет' (при вводе 'нет' вы переходите в главное меню, и статистика сбрасывается): ";
	std::string continueGame;
	std::getline(std::cin, continueGame);
	checkYesOrNo(continueGame);
	if (continueGame == "да") {
		system("cls");
		std::string choose_of_categories;
		std::cout << "\nВыберите категорию:" << std::endl;
		std::cout << "Животные - 1\n";
		std::cout << "Спорт - 2\n";
		std::cout << "Еда - 3\n";
		std::cout << "Природа - 4\n";
		std::cout << "Цвета - 5\n";
		std::cout << "Профессии - 6\n";
		std::cout << "Любая категория - 7\n";
		std::getline(std::cin, choose_of_categories);
		int chooseOfCategories = checkOfInput(choose_of_categories);
		THE_WORD = makingWordFromCategories(chooseOfCategories);
		system("cls");
		wrong = 0;
		used = "";
		std::string soFar(THE_WORD.size(), '-');
		gameplayFor1Player(MAX_WRONG, wrong, THE_WORD, used, soFar, count);
	}
	else {
		system("cls");
		launchOfTheGame();
	}
}

std::string makingName1() {
	std::string name1;
	std::cout << "Введите имя для первого игрока: ";
	std::getline(std::cin, name1);
	return name1;
}

std::string makingName2() {
	std::string name2;
	std::cout << "Введите имя для второго игрока: ";
	std::getline(std::cin, name2);
	return name2;
}

void launchOfTheGame() { //запуск игры
	std::cout << "\n\n--------------------------------------------------\n";
	std::cout << "Добро пожаловать в игру Виселица!\n";
	std::cout << "Для начала игры напишите 'да', для выхода - 'нет': ";
	std::getline(std::cin, check);
	checkYesOrNo(check);
	system("cls");
	int countWinFor1 = 0;
	int countWinFor2 = 0;
	int count = 0;
	while (check == "да") {
		const int MAX_WRONG = 8;
		std::string THE_WORD;
		int wrong = 0;
		std::string players;
		std::string check;
		std::string name1;
		std::string name2;
		std::cout << "\nВыберите количество игроков: 1 игрок - 1,  2 игрока - 2 ";
		std::getline(std::cin, players);
		checkOfPlayers(players);
		if (players == "2") {
			std::cout << std::endl;
			name1 = makingName1();
			name2 = makingName2();
		}
		std::string choose_of_categories;
		std::cout << "\nВыберите категорию:" << std::endl;
		std::cout << "Животные - 1\n";
		std::cout << "Спорт - 2\n";
		std::cout << "Еда - 3\n";
		std::cout << "Природа - 4\n";
		std::cout << "Цвета - 5\n";
		std::cout << "Профессии - 6\n";
		std::cout << "Любая категория - 7\n";
		std::getline(std::cin, choose_of_categories);
		int chooseOfCategories = checkOfInput(choose_of_categories);
		THE_WORD = makingWordFromCategories(chooseOfCategories);
		wrong = 0;
		std::string used = "";
		std::string soFar(THE_WORD.size(), '-');
		system("cls");
		short flagForPlayers = 1;
		while (players == "2") {
			gameplayFor2Players(MAX_WRONG, wrong, THE_WORD, used, flagForPlayers, countWinFor1, countWinFor2, name1, name2);
			break;
		}
		while (players == "1") {
			gameplayFor1Player(MAX_WRONG, wrong, THE_WORD, used, soFar, count);
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(static_cast<unsigned int>(time(0)));
	launchOfTheGame();
	std::cout << "\n\nДо скорых встреч! <3\n\n";
	return 0;
}
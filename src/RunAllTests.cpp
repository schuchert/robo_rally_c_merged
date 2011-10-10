#include <CppUTest/CommandLineTestRunner.h>

int main(int argc, const char **argv) {
	CommandLineTestRunner r(0, 0, 0);

	return CommandLineTestRunner::RunAllTests(argc, argv);
}

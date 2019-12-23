#include <JunoSync/Config.hpp>
#include <libconfig.h++>

using namespace JunoSync;

int Config::init(const boost::filesystem::path &confPath)
{
	libconfig::Config cfg;

	try
	{
		cfg.readFile(confPath);
	}
	catch (const libconfig::FileIOException &fioex)
	{
		// TODO: Replace cout with a good logging library.
		// File probably doesn't exist. Try creating a new one
		std::cout << "Could not open configuration file" << std::endl;
		Config::createDefault(confPath);
	}
	catch (const ParseExpression &pex)
	{
		// TODO: Replace cerr with a good logging library.
		std::cerr << "File " << pex.getFile() << " error on line " <<
			pex.getLine() << ": " << pex.getError() << std::endl;
		return 0b00000001;
	}
}

void Config::createDefault(const boost::filesystem::path &confPath)
{

}
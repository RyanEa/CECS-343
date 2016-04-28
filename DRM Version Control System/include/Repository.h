#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>
#include <fstream>
#include <string>
#include <experimental\filesystem>


class Repository {
    /*
        This class manages everything related to repository actions.
    */
private:
    const std::string mRepositoryFolderName;

    void CreateRepository(const std::string);
    void CreateProjectTree() const;
    void CreateManifest(std::string, std::string, std::string) const;
    const std::string CheckSum(const std::string) const;
    const std::vector<std::string> DateStamp() const;
    const std::string GetPreviousManifest(std::string) const;
    const std::string GetRepositoryPath(std::string, std::string, std::string) const;
    const std::string GetFileLocation(std::string, std::string) const;
    const std::string GetPreviousProjectTreeLocation(std::string) const;

public:
    Repository();
    ~Repository();
    void Initialize();
    void Update();
    void CheckIn(std::string, std::string);
    void CheckOut(std::string, std::string, std::string);
};

#endif
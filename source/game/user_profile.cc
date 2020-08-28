#include "user_profile.h"

#include <cstring>
#include <direct.h>
#include <fstream>
#include <iostream>

namespace {
const std::string gProfilesFolderPath = "profiles";
const std::string gProfileFileFormat = "txt";
const int kNameBufferSize = 256;
}  // namespace

UserProfile::UserProfile(const GameWindowContext& game_window_context)
    : level_manager_(game_window_context, 1) {
}

void UserProfile::SetName(const std::string& name) {
  name_ = name;
}

std::string UserProfile::name() const {
  return name_;
}

LevelManager& UserProfile::level_manager() {
  return level_manager_;
}

bool UserProfile::LoadFromConfigFile(const std::string& user_name) {
  std::fstream f(gProfilesFolderPath + "/" + user_name + "." + gProfileFileFormat, std::ios::in | std::ios::binary);
  if (!f.fail()) {
    char buf[kNameBufferSize];
    f.read(buf, kNameBufferSize * sizeof(char));
    name_ = buf;
    level_manager_.LoadFromFile(&f);
    f.close();
    return true;
  }
  return false;
}

void UserProfile::SaveToConfigFile() const {
  _mkdir(gProfilesFolderPath.c_str());
  std::fstream f(gProfilesFolderPath + "/" + name_ + "." + gProfileFileFormat, std::ios::out | std::ios::binary);
  char buf[kNameBufferSize];
  std::strncpy(buf, name_.c_str(), kNameBufferSize);
  f.write(buf, kNameBufferSize * sizeof(char));
  level_manager_.SaveToFile(&f);
  f.close();
}
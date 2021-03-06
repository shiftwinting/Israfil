#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include <vector>
#include "qqmusic.h"
#include "IsrafilBase/IsrafilBase.h"

using namespace Israfil::QQMusic;
using namespace Israfil::SongBase;
using std::vector;


TEST_CASE("Israfil::QQMusic Basic Tests - Search", "QQMusic") {
  vector<Song> ret;
  QQMusic     *qm = new QQMusic();
  qm->SearchSong("盛世回首", ret);
  dbg(ret.size());

  for (int i = 0; i < ret.size(); i++) {
    std::cout << ret[i].sName << " :: " << ret[i].sSingers[0].mName << " :: " << ret[i].sMp3URLs[0] \
              << " :: " << ret[i].sLyricsURLs[0] << " : "                                           \
              << ret[i].sPicURLs[0] << " vs " << ret[i].sAlbum.aPicURL << std::endl;
  }

  std::cout << SongListToJson(ret) << std::endl;
}

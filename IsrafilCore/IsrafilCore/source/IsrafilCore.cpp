/*=============================================================================
#     FileName: IsrafilCore.cpp
#         Desc: IsrafilCore Main Cpp file, invokes all public function
#       Author: LER0ever
#        Email: etasry@gmail.com
#     HomePage: http://yirong.ml
#      Version: 0.0.1
#   LastChange: 2016-08-12 16:57:53
#      History:
=============================================================================*/
#include <IsrafilCore/IsrafilCore.h>

namespace Israfil {
namespace Core {
IsrafilCore::IsrafilCore()
{
  pQM = new Israfil::QQMusic::QQMusic();
  pNE = new Israfil::Netease::Netease();
}

SongList IsrafilCore::SearchSong(std::string strName)
{
  // currently just return the qm search result
  SongList retSL;
  bool     bSS = pQM->SearchSong(strName, retSL);

  if (bSS == true) bSS = pNE->SearchSong(strName, retSL);
  dbg(bSS);
  return retSL;
}

SongListInfoList IsrafilCore::GetUserSongList(std::string strUserID) {
  SongListInfoList retSLIL;
  bool bSuc = pNE->GetUserSongList(strUserID, retSLIL);

  if (bSuc == false) dbgerr(strUserID);
  return retSLIL;
}

SongList IsrafilCore::GetSongsInSLD(std::string strSongListID){
  //SongList retSL;
  SongListDetail tmpSLD;
  pNE->GetSongListDetail(strSongListID, tmpSLD);
  return tmpSLD.slTracks;
}

Song IsrafilCore::GetAltSong(Song Orig){
  return Orig; //TODO: finish this func
}

}
}

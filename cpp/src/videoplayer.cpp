#include "videoplayer.h"
#include <iostream>
#include <stdlib.h>



void VideoPlayer::numberOfVideos() {
  std::cout << mVideoLibrary.getVideos().size() << " videos in the library"
            << std::endl;
}

void VideoPlayer::showAllVideos() {
  std::cout << "Here's a list of all available videos:" << std::endl;

  //loop on each video in library
  for(auto v: mVideoLibrary.getVideos())
  {
    //print title and id
    std::cout<<v.getTitle()<<" "<<"("<<v.getVideoId()<<")"<<"  [";

    //loop on tags
    for(auto s: v.getTags())
    {
      std::cout<<s<<" ";
    }

    std::cout<<"]\n";
  }
  
}

void VideoPlayer::playVideo(const std::string& videoId) {

  const Video* video = mVideoLibrary.getVideo(videoId);

  if(video == nullptr)
  {
    std::cout<<"Cannot play video: Video does not exist\n";
  }
  else
  {
    if(playingStatus)
    {
      stopVideo();
    }
    else
    {
      playingVideoT = video->getTitle();
      playingStatus = true;
      std::cout<<"Playing video: "<<playingVideoT<<std::endl;

      playingVideo = *video;
    }
  }

  delete video;
}

void VideoPlayer::stopVideo() {

  std::cout<<"Stopping video: "<<playingVideoT<<std::endl;
  playingStatus = false;
  playingVideoT = "";

}

void VideoPlayer::playRandomVideo() {
  int randomNum = rand() % videos.size();

  Video tmpVideo = videos[randomNum];

  playVideo(tmpVideo.getVideoId()); 

}

void VideoPlayer::pauseVideo() {
  if(pauseStatus)
  {
    std::cout << "Video already paused: "<<pasuedVideoT<< std::endl;
  }
  else
  {
    pasuedVideoT = playingVideoT;
    pauseStatus = true;
    std::cout << "Pausing video: "<<pasuedVideoT<< std::endl;

  }
}

void VideoPlayer::continueVideo() {
  if(pauseStatus)
  {
    std::cout<<"Continuing video: "<<pasuedVideoT<<std::endl;
    pauseStatus = false;
    pasuedVideoT = "";
  }
  else
  {
    std::cout<<"Cannot continue video: Video is not paused"<<std::endl;
  }
}

void VideoPlayer::showPlaying() {
  std::cout << "Currently playing: " << playingVideo.getTitle()<<" ("<<playingVideo.getVideoId()<<") ";
  for(auto v: playingVideo.getTags())
  {
    std::cout<<v<<" ";
  }
  std::cout<<"\n";
  
}

void VideoPlayer::createPlaylist(const std::string& playlistName) {
  std::cout << "createPlaylist needs implementation" << std::endl;
}

void VideoPlayer::addVideoToPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
  std::cout << "addVideoToPlaylist needs implementation" << std::endl;
}

void VideoPlayer::showAllPlaylists() {
  std::cout << "showAllPlaylists needs implementation" << std::endl;
}

void VideoPlayer::showPlaylist(const std::string& playlistName) {
  std::cout << "showPlaylist needs implementation" << std::endl;
}

void VideoPlayer::removeFromPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
  std::cout << "removeFromPlaylist needs implementation" << std::endl;
}

void VideoPlayer::clearPlaylist(const std::string& playlistName) {
  std::cout << "clearPlaylist needs implementation" << std::endl;
}

void VideoPlayer::deletePlaylist(const std::string& playlistName) {
  std::cout << "deletePlaylist needs implementation" << std::endl;
}

void VideoPlayer::searchVideos(const std::string& searchTerm) {
  std::cout << "searchVideos needs implementation" << std::endl;
}

void VideoPlayer::searchVideosWithTag(const std::string& videoTag) {
  std::cout << "searchVideosWithTag needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId, const std::string& reason) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::allowVideo(const std::string& videoId) {
  std::cout << "allowVideo needs implementation" << std::endl;
}

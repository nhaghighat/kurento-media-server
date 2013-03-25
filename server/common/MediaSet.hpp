/*
 * MediaSet.hpp - Kurento Media Server
 *
 * Copyright (C) 2013 Kurento
 * Contact: Miguel París Díaz <mparisdiaz@gmail.com>
 * Contact: José Antonio Santos Cadenas <santoscadenas@kurento.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __MEDIA_SET_H__
#define __MEDIA_SET_H__

#include "ConcurrentMap.hpp"
#include "types/MediaFactory.hpp"
#include "types/MediaPlayer.hpp"
#include "types/MediaRecorder.hpp"
#include "types/Stream.hpp"
#include "types/Mixer.hpp"

namespace kurento
{

class MediaSet
{
public:
  MediaSet () {};

  void put (std::shared_ptr<MediaObject> mediaObject);
  void remove (const MediaObject &mediaObject);
  int size();
  std::shared_ptr<MediaFactory> getMediaFactory (const MediaObject &mediaObject);
  std::shared_ptr<Joinable> getJoinable (const MediaObject &mediaObject);
  std::shared_ptr< MediaPlayer> getMediaPlayer (const MediaObject &mediaObject);
  std::shared_ptr<MediaRecorder> getMediaRecorder (const MediaObject &mediaObject);
  std::shared_ptr<Stream> getStream (const MediaObject &mediaObject);
  std::shared_ptr<Mixer> getMixer (const MediaObject &mediaObject);
  std::shared_ptr<MixerPort> getMixerPort (const MediaObject &mediaObject);

private:
  ConcurrentMap<ObjectId, std::shared_ptr<MediaObject> > mediaObjectMap;
};

} // kurento

#endif /* __MEDIA_SET_H__ */
/*
 * ijkplayer_android_def.h
 *
 * Copyright (c) 2013 Bilibili
 * Copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef IJKPLAYER_ANDROID__IJKPLAYER_ANDROID_DEF_H
#define IJKPLAYER_ANDROID__IJKPLAYER_ANDROID_DEF_H

/*
 * frameworks/av/include/media/mediaplayer.h
 */


//
enum media_event_type {
    MEDIA_NOP               = 0,        // interface test message
    MEDIA_PREPARED          = 1,
    MEDIA_PLAYBACK_COMPLETE = 2,
    MEDIA_BUFFERING_UPDATE  = 3,        // arg1 = percentage, arg2 = cached duration
    MEDIA_SEEK_COMPLETE     = 4,
    MEDIA_SET_VIDEO_SIZE    = 5,        // arg1 = width, arg2 = height
    MEDIA_GET_IMG_STATE     = 6,        // arg1 = timestamp, arg2 = result code, obj = file name
    MEDIA_TIMED_TEXT        = 99,       // not supported yet
    MEDIA_ERROR             = 100,      // arg1, arg2
    MEDIA_INFO              = 200,      // arg1, arg2
    MEDIA_IJK_LOG           = 300,      // obj
    MEDIA_IJK_ERROR_LOG     = 400,      // arg1, arg2
    MEDIA_IJK_ERROR         = 500,      // arg1, arg2




    MEDIA_SET_VIDEO_SAR     = 10001,    // arg1 = sar.num, arg2 = sar.den
};

// Generic error codes for the media player framework.  Errors are fatal, the
// playback must abort.
//
// Errors are communicated back to the client using the
// MediaPlayerListener::notify method defined below.
// In this situation, 'notify' is invoked with the following:
//   'msg' is set to MEDIA_ERROR.
//   'ext1' should be a value from the enum media_error_type.
//   'ext2' contains an implementation dependant error code to provide
//          more details. Should default to 0 when not used.
//
// The codes are distributed as follow:
//   0xx: Reserved
//   1xx: Android Player errors. Something went wrong inside the MediaPlayer.
//   2xx: Media errors (e.g Codec not supported). There is a problem with the
//        media itself.
//   3xx: Runtime errors. Some extraordinary condition arose making the playback
//        impossible.
//
//
//   need same with android/contrib/ffmpeg-armv7a/libavutil/log.h
//
enum media_error_type {
    // 0xx
    MEDIA_ERROR_UNKNOWN = 1,
    // 1xx
    MEDIA_ERROR_SERVER_DIED = 100,
    // 2xx
    MEDIA_ERROR_NOT_VALID_FOR_PROGRESSIVE_PLAYBACK = 200,
    // 3xx

    // -xx
    MEDIA_ERROR_IO          = -1004,
    MEDIA_ERROR_MALFORMED   = -1007,
    MEDIA_ERROR_UNSUPPORTED = -1010,
    MEDIA_ERROR_TIMED_OUT   = -110,

    MEDIA_ERROR_IJK_PLAYER  = -10000,

    MEDIA_ERROR_IJK_PLAYER_STREAM_OPEN                  = -10010,//-10010

    MEDIA_ERROR_IJK_PLAYER_FRAME_QUEUE_INIT_VIDEO       = -10011,//crash
    MEDIA_ERROR_IJK_PLAYER_FRAME_QUEUE_INIT_SUBTITLE    = -10012,//crash
    MEDIA_ERROR_IJK_PLAYER_FRAME_QUEUE_INIT_AUDIO       = -10013,//crash
    MEDIA_ERROR_IJK_PLAYER_PACKET_QUEUE_INIT_ALL        = -10014,//crash
    MEDIA_ERROR_IJK_PLAYER_CONTINUE_READ_THREAD         = -10015,//crash
    MEDIA_ERROR_IJK_PLAYER_VIDEO_REFRESH_TID            = -10016,//-10016-->-10010-->crash
    MEDIA_ERROR_IJK_PLAYER_READ_TID                     = -10017,//-10017-->-10023-->-10010
    MEDIA_ERROR_IJK_PLAYER_FILE_NAME                    = -10018,//crash
    MEDIA_ERROR_IJK_PLAYER_AV_MALLOCZ                   = -10019,//-10019-->-10010

    MEDIA_ERROR_IJK_PLAYER_WAIT_MUTEX                   = -10021,//-10021
    MEDIA_ERROR_IJK_PLAYER_AVFORMAT_ALLOC_CONTEXT       = -10022,//-10022
    MEDIA_ERROR_IJK_PLAYER_AVFORMAT_OPEN_INPUT          = -10023,//-10023
    MEDIA_ERROR_IJK_PLAYER_AVFORMAT_FIND_STREAM_INFO    = -10024,//-10024
    MEDIA_ERROR_IJK_PLAYER_NO_VIDEO_OR_AUDIO_STREAM     = -10025,//-10025
    MEDIA_ERROR_IJK_PLAYER_AV_DICT_GET                  = -10026,//-10026
    MEDIA_ERROR_IJK_PLAYER_AV_COPY_PACKET               = -10027,//-10027
    MEDIA_ERROR_IJK_PLAYER_AUTO_EXIT                    = -10028,//-10028

    /* stream_component_open */ /* 直接影响 MEDIA_ERROR_IJK_PLAYER_NO_VIDEO_OR_AUDIO_STREAM(-10025) */
    MEDIA_ERROR_IJK_PLAYER_AVCODEC_NOT_FIND             = -10031,//-10031-->-10025
    MEDIA_ERROR_IJK_PLAYER_AVCODEC_OPEN                 = -10032,//-10032-->-10025
    //MEDIA_ERROR_IJK_PLAYER_AUDIO_OPEN                   = -10033,
    //MEDIA_ERROR_IJK_PLAYER_AUDIO_DECODER_START          = -10034,
    MEDIA_ERROR_IJK_PLAYER_OPEN_VIDEO_DECODER           = -10035,//-10035-->第二次crash
    //MEDIA_ERROR_IJK_PLAYER_VIDEO_DECODER_START          = -10036,
    MEDIA_ERROR_IJK_PLAYER_AVCODEC_PARAMETERS_TO_CONTEXT= -10037,//-10037-->-10025
    MEDIA_ERROR_IJK_PLAYER_CONFIGURE_AUDIO_FILTERS      = -10038,//
    MEDIA_ERROR_IJK_PLAYER_AVCODEC_ALLOC_CONTEXT3       = -10039,//-10039-->-10025
    MEDIA_ERROR_IJK_PLAYER_STREAM_INDEX                 = -10040,//-10040-->-10025

};

// Info and warning codes for the media player framework.  These are non fatal,
// the playback is going on but there might be some user visible issues.
//
// Info and warning messages are communicated back to the client using the
// MediaPlayerListener::notify method defined below.  In this situation,
// 'notify' is invoked with the following:
//   'msg' is set to MEDIA_INFO.
//   'ext1' should be a value from the enum media_info_type.
//   'ext2' contains an implementation dependant info code to provide
//          more details. Should default to 0 when not used.
//
// The codes are distributed as follow:
//   0xx: Reserved
//   7xx: Android Player info/warning (e.g player lagging behind.)
//   8xx: Media info/warning (e.g media badly interleaved.)
//
enum media_info_type {
    // 0xx
    MEDIA_INFO_UNKNOWN = 1,
    // The player was started because it was used as the next player for another
    // player, which just completed playback
    MEDIA_INFO_STARTED_AS_NEXT = 2,
    // The player just pushed the very first video frame for rendering
    MEDIA_INFO_VIDEO_RENDERING_START = 3,
    // 7xx
    // The video is too complex for the decoder: it can't decode frames fast
    // enough. Possibly only the audio plays fine at this stage.
    MEDIA_INFO_VIDEO_TRACK_LAGGING = 700,
    // MediaPlayer is temporarily pausing playback internally in order to
    // buffer more data.
    MEDIA_INFO_BUFFERING_START = 701,
    // MediaPlayer is resuming playback after filling buffers.
    MEDIA_INFO_BUFFERING_END = 702,
    // Bandwidth in recent past
    MEDIA_INFO_NETWORK_BANDWIDTH = 703,

    // 8xx
    // Bad interleaving means that a media has been improperly interleaved or not
    // interleaved at all, e.g has all the video samples first then all the audio
    // ones. Video is playing but a lot of disk seek may be happening.
    MEDIA_INFO_BAD_INTERLEAVING = 800,
    // The media is not seekable (e.g live stream).
    MEDIA_INFO_NOT_SEEKABLE = 801,
    // New media metadata is available.
    MEDIA_INFO_METADATA_UPDATE = 802,

    //9xx
    MEDIA_INFO_TIMED_TEXT_ERROR = 900,

    //100xx
    MEDIA_INFO_VIDEO_ROTATION_CHANGED = 10001,
    MEDIA_INFO_AUDIO_RENDERING_START = 10002,

    MEDIA_INFO_MEDIA_ACCURATE_SEEK_COMPLETE = 10100,
};

typedef struct ijkmp_mediacodecinfo_context
{
    char mime_type[128];    //< in
    int  profile;           //< in
    int  level;             //< in
    char codec_name[128];   //< out
} ijkmp_mediacodecinfo_context;

#endif

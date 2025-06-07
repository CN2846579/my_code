#pragma once    
#include <SDL_mixer.h>  
class SDL_VOICE  
{  
public:  
   SDL_VOICE(const char* Path);  
   ~SDL_VOICE();  
   void Play(int loop = 0) {  
       if (music) Mix_PlayMusic(music, loop);  
   }  
   // Í£Ö¹²¥·ÅÒôÀÖ
   void Stop() {
	   Mix_HaltMusic();
   }
   // ÔÝÍ£²¥·ÅÒôÀÖ
   void Pause() {
	   Mix_PauseMusic();
   }
   // »Ö¸´²¥·ÅÒôÀÖ
   void Resume() {
	   Mix_ResumeMusic();
   }
   // ÉèÖÃÒôÁ¿£¬·¶Î§´Ó0µ½MIX_MAX_VOLUME
   void SetVolume(int volume) {
	   Mix_VolumeMusic(volume);
   }

private:  
   Mix_Music* music;  
};  

SDL_VOICE::SDL_VOICE(const char* Path)
{  
   SDL_Init(SDL_INIT_AUDIO);  
   Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);  
   Mix_Music* music = Mix_LoadMUS(Path);  
   if (!music) {  
       printf("Failed to load music: %s\n", Mix_GetError());  
   }  
   else {  
       this->music = music;  
       printf("Music loaded successfully\n");  
   }  
}  

SDL_VOICE::~SDL_VOICE()  
{  
   if (t.joinable()) {  
       t.join(); 
   }  
   if(music)
   Mix_FreeMusic(music);
   Mix_CloseAudio();  
   SDL_Quit();  
   printf("SDL_VOICE destroyed\n");  
}
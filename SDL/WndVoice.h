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
   // ֹͣ��������
   void Stop() {
	   Mix_HaltMusic();
   }
   // ��ͣ��������
   void Pause() {
	   Mix_PauseMusic();
   }
   // �ָ���������
   void Resume() {
	   Mix_ResumeMusic();
   }
   // ������������Χ��0��MIX_MAX_VOLUME
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
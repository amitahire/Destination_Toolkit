#ifndef CWIDGETRENDERER_H
#define CWIDGETRENDERER_H
#include <string>
#include "ITexture.h"

namespace MY_UI_Too{
	namespace Interfaces{
		// this renderer is a Buffered renderer, meaning all data sent to is is cached so work does not need to be redone each fram if it is not needed. This greatly improves rendering speed
		class IRenderer{// This is a purly virtual base class that users should derive from in order to create an Open Gl renderer, or a Direct X renderer
		public:

			virtual ~IRenderer(){ }// make sure to free any resorces that you allocate in the derived destructor 
			virtual bool Init()=0;
			virtual void DeInit() =0;
			virtual void Begin(MY_UI_Too::Interfaces::ITexture* texture=nullptr)=0;// this should set all necessary render states, i.e. alpha blending, no depth testing, etc
			virtual void End()=0;// this should restore all previous device states
			virtual void StartNewBatch()=0;
			virtual void Draw()=0;

			// these functions will buffer everything sent to them and nothing will be drawn until the drawbuffered is called
			virtual void DrawTexturedRect_Clip( MY_UI_Too::Interfaces::ITexture* Texture, MY_UI_Too::Utilities::UVs& uvs, MY_UI_Too::Utilities::Rect rect, MY_UI_Too::Utilities::Color color_tl = MY_UI_Too::Utilities::White, MY_UI_Too::Utilities::Color color_tr = MY_UI_Too::Utilities::White, MY_UI_Too::Utilities::Color color_bl = MY_UI_Too::Utilities::White, MY_UI_Too::Utilities::Color color_br = MY_UI_Too::Utilities::White, bool getnewbuffer=false)=0;
			virtual void DrawTexturedRect_NoClip( MY_UI_Too::Interfaces::ITexture* Texture,  MY_UI_Too::Utilities::UVs& uvs, MY_UI_Too::Utilities::Rect rect, MY_UI_Too::Utilities::Color color_tl = MY_UI_Too::Utilities::White, MY_UI_Too::Utilities::Color color_tr = MY_UI_Too::Utilities::White, MY_UI_Too::Utilities::Color color_bl = MY_UI_Too::Utilities::White, MY_UI_Too::Utilities::Color color_br = MY_UI_Too::Utilities::White, bool getnewbuffer=false)=0;

			virtual void StartClip(MY_UI_Too::Utilities::Rect& rect)=0;
			virtual void EndClip()=0;

			virtual MY_UI_Too::Interfaces::ITexture* LoadTexture(std::string filename, bool as_rendertarget=false)=0;
			virtual MY_UI_Too::Interfaces::ITexture* CreateTexture(unsigned int width, unsigned int height, Utilities::Color* buffer=nullptr, bool as_rendertarget=false)=0;
			virtual void Set_Size(MY_UI_Too::Utilities::Point screensize) =0;// this is called when the screen sets a new window dimensions
			virtual MY_UI_Too::Utilities::Point Get_Size() =0;// get the current size of the renderer window
			virtual unsigned int GetDrawCalls()const =0;
		};
	};

};

#endif

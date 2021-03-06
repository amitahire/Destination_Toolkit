#ifndef MESH_UI
#define MESH_UI
#include <functional>

namespace MY_UI{
	namespace Controls{
		class Button;
		class File_Selector;
	}
}
class Base_Mesh;
class Mesh_UI{
public:

	Mesh_UI();
	~Mesh_UI();
	void Set_AddMesh_Func(std::function<bool (Base_Mesh* m)> f){ AddMesh = f;}
	//takes a string with a semi colon as a delimeter, for example   "*.exe;*.jpg;"
	void SetFileExts(std::string s){ FileExtentions =s; }
	void buttonclicked_static();
	void buttonclicked_animated();
	void Fileselected();

protected:
	
	std::string FileExtentions;
	std::function<bool (Base_Mesh* m)> AddMesh;
	MY_UI::Controls::File_Selector* FileSelector;
};


#endif
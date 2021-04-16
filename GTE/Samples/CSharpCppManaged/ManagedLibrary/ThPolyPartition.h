#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"

namespace CLI
{
	public ref class ThPolygon : public ManagedObject<gte::ThPolygon>
	{
	public:
		ThPolygon::ThPolygon() :ManagedObject(new gte::ThPolygon())
		{
			//
		}
	public :
		property cli::array<double>^ Shell;
		property cli::array<cli::array<double>^>^ Holes;
	};
		 
	public ref class ThPolyPartition : public ManagedObject<gte::ThPolyPartition>
	{
	public:
		ThPolyPartition() : ManagedObject(new gte::ThPolyPartition())
		{
			//
		}
	public:
		property cli::array<cli::array<double>^>^ Results;

	public:
		bool TriangulateEC(ThPolygon^ thPolygon);
	};
}

using CLI;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpApplication
{
    class PipeDiagramTest
    {
        ThPipeSystemDiagramMgd SystemDiagramMethods;
        public PipeDiagramTest(ThPipeSystemDiagramMgd nativeWarpper)
        {
            SystemDiagramMethods = nativeWarpper;
        }

        public string ProcessMainBranchs(string geojson)
        {
            var output = SystemDiagramMethods.ProcessMainBranchs(geojson);
            return output;
        }

        public void ProcessMainBranchsByFileName(string inputFile, string outputFile)
        {
            string inputGeoJson = File.ReadAllText(inputFile);
            var output = SystemDiagramMethods.ProcessMainBranchs(inputGeoJson);

            File.WriteAllText(outputFile, output);
        }

        public void TestProcessMainBranchs()
        {
            string inputFile = @"D:\DATA\Git\GeometricTools\GTE\Samples\CSharpCppManaged\CppLibrary\GroupingPipe\data\pipe\case-0.geojson";
            string outputFile = @"D:\xx.geojson";
            ProcessMainBranchsByFileName(inputFile, outputFile);
        }
    }
}

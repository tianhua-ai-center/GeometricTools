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

        public void ProcessGroupingByFileName(string inputFile, string outputFile)
        {
            string inputGeoJson = File.ReadAllText(inputFile);
            var output = SystemDiagramMethods.ProcessGrouping(inputGeoJson);
            File.WriteAllText(outputFile, output);
        }

        public void TestProcessMainBranchs()
        {
            //string inputFile = @"D:\DATA\Git\GeometricTools\GTE\Samples\CSharpCppManaged\CppLibrary\GroupingPipe\data\pipe\case-0.geojson";
            string inputFile = @"C:\Users\wangwenguang\Desktop\column_test.geojson";
            string outputFile = @"D:\mainbranch.geojson";
            ProcessMainBranchsByFileName(inputFile, outputFile);
        }

        public void TestProcessGrouping()
        {
            string inputFile = @"C:\Users\wangwenguang\Desktop\test_7_9.geojson";
            string outputFile = @"D:\grouping.geojson";
            ProcessGroupingByFileName(inputFile, outputFile);
        }
    }
}

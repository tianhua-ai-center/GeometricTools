﻿using CLI;
using System;
using System.IO;
using Newtonsoft.Json;
using NetTopologySuite.IO;
using NetTopologySuite.Features;

// The framework is based on the nicely written article "Creating a C++/CLI wrapper",
// https://www.red-gate.com/simple-talk/dotnet/net-development/creating-ccli-wrapper/
// by Mircea Oprea.  If you read this article, the native library originally was
// created as a dynamic library, but that has an overstrike and is replaced by a
// static library.  This is a consequence of the discussion at the end of the article
// where Maxence points out that this avoids DLL export problems.  However, as Maxence
// says, you can add __declspec(dllexport) tags to the functions you want exported so
// that the DLL is actually generated by the native library (in this solution, the
// CppLibrary).
//
// BEFORE BUILDING, change the configuration to Release and the architecture type
// to x64.  If you choose to run x86, you must launch the properties dialog for
// the CSharpApplication project.  Select the Build item and change the platform
// architecture from x64 to x86.  I do not know enough about mixed-language project
// management in Visual Studio to figure out whether this can happen automatically
// by selecting the config/architecture UI control from the Visual Studio toolbar.
// Do not use the DebugGL4 or ReleaseGL4; these are part of GTEngine and  are not
// hooked up via the configuration manager.  BEFORE RUNNING, set the start-up
// project to CSharpApplication; right-click that project and choose
// "Set as Startup Project".

namespace CSharpApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            //var prepair = new ThPolygonRepairerMgd();
            //var wkt = prepair.MakeValid("POLYGON((0 0, 10 0, 15 5, 10 0, 10 10, 0 10, 0 0))");
            //var wktReader = new WKTReader();
            //var geometry = wktReader.Read(wkt);

            //PipeDiagramTest t = new PipeDiagramTest(new CLI.ThPipeSystemDiagramMgd());
            //t.TestProcessMainBranchs();
            //t.TestProcessGrouping();

            //ThCableRouterMgd cableRouter = new ThCableRouterMgd();
            //var strInputGeoJson = "";
            //var routedCables = cableRouter.RouteCable(strInputGeoJson, 25);

            //input
            var path = Console.ReadLine();

            ////CenterLine
            //var strInputGeoJson = File.ReadAllText(path);
            //var engine = new ThPolygonCenterLineMgd();
            //var result = engine.Generate(strInputGeoJson);

            //AFAS
            var strInputGeoJson = File.ReadAllText(path);
            ThAFASPlacementEngineMgd engine = new ThAFASPlacementEngineMgd();
            ThAFASPlacementContextMgd context = new ThAFASPlacementContextMgd()
            {
                StepDistance = 20000,
                SpaceSampleLength = 1000,
                MountMode = ThAFASPlacementMountModeMgd.Wall,
            };
            var result = engine.Place(strInputGeoJson, context);

            //Export result to GeoJSON file
            var features = Export2NTSFeatures(result);
            var geojson = Features2GeoJSON(features);
            var file = Path.Combine(
                Path.GetDirectoryName(path),
                Path.GetFileNameWithoutExtension(path) + ".output.geojson");
            Export2File(geojson, file);
        }

        static FeatureCollection Export2NTSFeatures(string geojson)
        {
            var serializer = GeoJsonSerializer.Create();
            using (var stringReader = new StringReader(geojson))
            using (var jsonReader = new JsonTextReader(stringReader))
            {
                return serializer.Deserialize<FeatureCollection>(jsonReader);
            }
        }

        static string Features2GeoJSON(FeatureCollection features)
        {
            var serializer = GeoJsonSerializer.Create();
            using (var stringWriter = new StringWriter())
            using (var jsonWriter = new JsonTextWriter(stringWriter)
            {
                Indentation = 4,
                IndentChar = ' ',
                Formatting = Formatting.Indented,
            })
            {
                serializer.Serialize(jsonWriter, features);
                return stringWriter.ToString();
            }
        }

        static void Export2File(string geojson, string file)
        {
            using (StreamWriter outputFile = new StreamWriter(file))
            {
                outputFile.Write(geojson);
            }
        }
    }
}

function Get-LatestMsbuildLocation {
  Param 
  (
    [bool] $allowPreviewVersions = $false
  )
  if ($allowPreviewVersions) {
    $latestVsInstallationInfo = Get-VSSetupInstance -All -Prerelease | Sort-Object -Property InstallationVersion -Descending | Select-Object -First 1
  }
  else {
    $latestVsInstallationInfo = Get-VSSetupInstance -All | Sort-Object -Property InstallationVersion -Descending | Select-Object -First 1
  }
  Write-Host "Latest version installed is $($latestVsInstallationInfo.InstallationVersion)"
  if ($latestVsInstallationInfo.InstallationVersion -like "15.*") {
    $msbuildLocation = "$($latestVsInstallationInfo.InstallationPath)\MSBuild\15.0\Bin\msbuild.exe"
    
    Write-Host "Located msbuild for Visual Studio 2017 in $msbuildLocation"
  }
  else {
    $msbuildLocation = "$($latestVsInstallationInfo.InstallationPath)\MSBuild\Current\Bin\msbuild.exe"
    Write-Host "Located msbuild in $msbuildLocation"
  }

  return $msbuildLocation
}
function Get-LatestDevenvLocation {
  Param 
  (
    [bool] $allowPreviewVersions = $false
  )
  if ($allowPreviewVersions) {
    $latestVsInstallationInfo = Get-VSSetupInstance -All -Prerelease | Sort-Object -Property InstallationVersion -Descending | Select-Object -First 1
  }
  else {
    $latestVsInstallationInfo = Get-VSSetupInstance -All | Sort-Object -Property InstallationVersion -Descending | Select-Object -First 1
  }
  Write-Host "Latest version installed is $($latestVsInstallationInfo.InstallationVersion)"

  $devenvLocation = "$($latestVsInstallationInfo.InstallationPath)\Common7\IDE\devenv.exe"
  Write-Host "Located devenv in $devenvLocation"

  return $msbuildLocation
}

function Set-DevEnvironmentVariables {
  Param 
  (
    [string] $acadVersion = ""
  )

  switch ($acadVersion) {
    "ACAD2012" {
      #

    }
    "ACAD2014" {
      #
    }
    "ACAD2016" {
      # Visual Studio 2013 Update 5 (12.0.40629.0)
      Set-EnvironmentVariable -Name 'VS_VERSION' -Value '12.0' -ForProcess
      Set-EnvironmentVariable -Name 'CGAL_VERSION' -Value '4.8' -ForProcess
      Set-EnvironmentVariable -Name 'GDAL_VERSION' -Value '2.23' -ForProcess
      Set-EnvironmentVariable -Name 'BOOST_VERSION' -Value '1.65.0' -ForProcess
    }
    "ACAD2018" {
      # Visual Studio 2015 Update 3 (14.0.25420.10)
      Set-EnvironmentVariable -Name 'VS_VERSION' -Value '14.0' -ForProcess
      Set-EnvironmentVariable -Name 'CGAL_VERSION' -Value '5.2.1' -ForProcess
      Set-EnvironmentVariable -Name 'GDAL_VERSION' -Value '3.2.1' -ForProcess
      Set-EnvironmentVariable -Name 'BOOST_VERSION' -Value '1.75.0' -ForProcess
    }
    default {
      #
    }
  }
}

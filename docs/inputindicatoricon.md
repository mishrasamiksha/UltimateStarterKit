## Introduction
A widget used to display a single input indicator image

## Dependencies
The <code>InputIndicatorIcon</code> relies on other components of this plugin to work:
<ul>
	<li><a href="../logger">Logger</a>: Used to log useful information to help you debug any issues you might experience</li>
</ul>

## Required Widgets
There is already a <code>InputIndicatorIcon_Implementation</code> that you can use in your projects. But if you create your own instance of this widget, you need to add the following before you can compile:
<table>
	<tr>
		<th>Name</th>
		<th>Description</th>
		<th>Type</th>
	</tr>
	<tr>
		<td>Container</td>
		<td>The size box container used to resize the image</td>
		<td>USizeBox*</td>
	</tr>
	<tr>
		<td>Image</td>
		<td>The image used to display the input indicator</td>
		<td>UImage*</td>
	</tr>
</table>

## API Reference
### Properties
<table>
	<tr>
		<th>Property</th>
		<th>Description</th>
		<th>Type</th>
		<th>Default Value</th>
	</tr>
</table>

### Functions
<table>
	<tr>
		<th>Name</th>
		<th>Description</th>
		<th>Params</th>
		<th>Return</th>
	</tr>
	<tr>
		<td>UpdateIcon</td>
		<td>Update the icon</td>
		<td><strong>Size (float)</strong><br/>The size of the image<br/><br/><strong>Icon (UTexture2D*)</strong><br/>The new icon</td>
		<td></td>
	</tr>
</table>

## Blueprint Usage
You can use the <code>InputIndicatorIcon</code> using Blueprints by adding one of the following nodes:
<ul>
	<li>Ultimate Starter Kit > UI > Update Icon</li>
</ul>

## C++ Usage
Before you can use the plugin, you first need to enable the plugin in your <code>Build.cs</code> file:
```c++
PublicDependencyModuleNames.Add("USK");
```

The <code>InputIndicatorIcon</code> can now be used in any of your C++ files:
```c++
#include "USK/Widgets/InputIndicatorIcon.h"

void ATestActor::Test()
{
	// InputIndicatorIcon is a pointer to the UInputIndicatorIcon
	InputIndicatorIcon->UpdateIcon(Size, Icon);
}
```

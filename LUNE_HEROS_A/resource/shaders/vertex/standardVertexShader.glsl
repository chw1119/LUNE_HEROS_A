#version 330 core

layout (location = 0) in vec3 vertexLocation;

layout (location = 1) in vec2 textureVertexLocation;

out vec2 TexCoord;

uniform vec2 sharedLocation;


void main()
{
    gl_Position = vec3(sharedLocation,0.f) + vertexLocation;
    TexCoord = textureVertexLocation;
}
#version 330

layout (triangles) in;
layout(triangle_strip, max_vertices = 3) out;
in vec2 vUV[];

out vec2 gUV;
void main()
{
	int i;

	for(i= 0; i < gl_in.length(); i++)
	{

		gl_Position = gl_in[i].gl_Position;
		gUV = vUV[i];
		EmitVertex();
	}
	EndPrimitive();
	
}
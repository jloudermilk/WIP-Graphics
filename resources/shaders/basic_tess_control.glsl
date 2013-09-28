#version 400

layout( vertices = 3 ) out;

in vec2 vUV[];
in vec4 vWorldPosition[];

out vec2 tcUV[];
out vec4 tcWorldPosition[];

void main()
{
	gl_out[ gl_InvocationID ].gl_Position = gl_in[ gl_InvocationID ].gl_Position;
	tcUV[gl_InvocationID] = vUV[gl_InvocationID];
	tcWorldPosition[gl_InvocationID] = vWorldPosition[gl_InvocationID];

	gl_TessLevelOuter[ 0 ] = 1.0;
	gl_TessLevelOuter[ 1 ] = 1.0;
	gl_TessLevelOuter[ 2 ] = 1.0;
	gl_TessLevelInner[ 0 ] = 1.0;
}
